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

const int mod=1e9+7;
int add(int a,int b){
    a+=b;
    if(a>=mod)
        a-=mod;
    return a;
}
int sub(int a,int b){
    a-=b;
    if(a<0)
        a+=mod;
    return a;
}
int mul(int a,int b){return (ll)a*b%mod;}
int pwrmod(int x,int k){
    int ans=1;
    for(;k;k>>=1,x=mul(x,x))
        if(k&1)
            ans=mul(ans,x);
    return ans;
}

int main()
{
    int n,m;
    scanf("%i %i",&n,&m);
    string s;
    cin >> s;
    int l=s.size(),mult=27;
    vector<ll> pre(l),suf(l);
    vector<int> pre2(l),suf2(l);
    pre[0]=pre2[0]=s[0]-'a';
    for(int i=1;i<l;i++)
        pre[i]=pre[i-1]*mult+s[i]-'a',pre2[i]=add(mul(pre2[i-1],mult),s[i]-'a');
    suf[l-1]=suf2[l-1]=s[l-1]-'a';
    int ml=mult,ml2=mult;
    for(int i=l-2;i>=0;i--,ml*=mult,ml2=mul(ml2,mult))
        suf[i]=suf[i+1]+(s[i]-'a')*ml,suf2[i]=add(suf2[i+1],mul(s[i]-'a',ml2));
    reverse(all(suf));
    reverse(all(suf2));
    int pos=-1,cnt=0;
    for(int i=0;i<m;i++)
    {
        int x;
        scanf("%i",&x);
        int st=x-1;
        x+=l-2;
        if(st>pos)
            cnt+=st-pos-1;
        else
            if(pre2[pos-st]!=suf2[pos-st])
                return 0*printf("0\n");
        pos=x;
    }
    cnt+=n-pos-1;
    printf("%i\n",pwrmod(26,cnt));
    return 0;
}