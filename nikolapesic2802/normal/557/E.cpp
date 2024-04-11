#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ll long long
#define pb push_back
#define sz(x) (int)(x).size()
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define D(x) cerr << #x << " is " << (x) << "\n";

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}

const int mod=1e9+7,puta=2;
int add(int a,int b)
{
    a+=b;
    if(a>=mod)
        a-=mod;
    return a;
}
int sub(int a,int b)
{
    a-=b;
    if(a<0)
        a+=mod;
    return a;
}
int mul(int a,int b)
{
    return (ll)a*b%mod;
}
const int N=5001;
bool yes[N][N];
struct node{
    int a,b,cnt;
};
vector<node> Trie;
int newNode()
{
    node a;
    a.a=a.b=-1;
    a.cnt=0;
    Trie.pb(a);
    return Trie.size()-1;
}
string s;
int root=newNode();
void dodaj(int i,int j,int tr=root)
{
    Trie[tr].cnt+=yes[i][j-1];
    if(j==(int)s.size())
        return;
    if(s[j]=='a'){
        if(Trie[tr].a==-1){
            int a=newNode();
            Trie[tr].a=a;
        }
        dodaj(i,j+1,Trie[tr].a);
    }
    else{
        if(Trie[tr].b==-1){
            int a=newNode();
            Trie[tr].b=a;
        }
        dodaj(i,j+1,Trie[tr].b);
    }
}
void calc(int tr=root)
{
    if(Trie[tr].a!=-1)
        calc(Trie[tr].a),Trie[tr].cnt+=Trie[Trie[tr].a].cnt;
    if(Trie[tr].b!=-1)
        calc(Trie[tr].b),Trie[tr].cnt+=Trie[Trie[tr].b].cnt;
}
int k;
string sol;
void getAns(int tr=root)
{
    int sum=0;
    if(Trie[tr].a!=-1)
        sum+=Trie[Trie[tr].a].cnt;
    if(Trie[tr].b!=-1)
        sum+=Trie[Trie[tr].b].cnt;
    if(k<Trie[tr].cnt-sum){
        cout << sol;
        exit(0);
    }
    else
        k-=Trie[tr].cnt-sum;
    if(Trie[tr].a!=-1){
        if(Trie[Trie[tr].a].cnt>k)
            sol+="a",getAns(Trie[tr].a);
        else
            k-=Trie[Trie[tr].a].cnt;
    }
    sol+="b";
    getAns(Trie[tr].b);
}
int main()
{
	cin >> s;
	int n=s.size();

	vector<int> pwr;
	pwr.pb(1);
	for(int i=1;i<=n;i++)
        pwr.pb(add(pwr.back(),pwr.back()));
	scanf("%i",&k);
	k--;
	vector<int> preh(n),sufh(n);
	for(int i=0;i<n;i++)
    {
        if(i>1)
            preh[i]=add(preh[i-2],preh[i-2]);
        if(s[i]=='b')
            preh[i]=add(preh[i],1);
    }
    for(int i=n-1;i>=0;i--)
    {
        if(i<n-2)
            sufh[i]=add(sufh[i+2],sufh[i+2]);
        if(s[i]=='b')
            sufh[i]=add(sufh[i],1);
    }
    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
        {
            int pola=(j-i+1)/2;
            int koliko=(pola+1)/2;
            if(koliko==0){
                yes[i][j]=1;
                continue;
            }
            int h1=preh[i+(koliko-1)*2];
            if(i>1)
                h1=sub(h1,mul(preh[i-2],pwr[koliko]));
            int h2=sufh[j-(koliko-1)*2];
            if(j<n-2)
                h2=sub(h2,mul(sufh[j+2],pwr[koliko]));
            if(h1==h2)
                yes[i][j]=1;
        }
    for(int i=0;i<n;i++)
        dodaj(i,i);
    calc();
    getAns();
    return 0;
}