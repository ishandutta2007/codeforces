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
#define ld long double

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const deque<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}

string a;
string mytest;
int limit;
vector<string> ask2(int l,int r){
    vector<string> sol;
    for(int i=l;i<=r;i++){
        string tr;
        for(int j=i;j<=r;j++){
            tr+=mytest[j-1];
            sol.pb(tr);
        }
    }
    for(auto &p:sol)
        sort(all(p));
    sort(all(sol));
    return sol;
}
vector<string> ask(int l,int r){
    printf("? %i %i\n",l,r);
    fflush(stdout);
    vector<string> sol;
    for(int i=l;i<=r;i++)
        for(int j=i;j<=r;j++)
            sol.pb(a),cin >> sol.back();
    for(auto &p:sol)
        sort(all(p));
    sort(all(sol));
    return sol;
}
int diff(string a,string b){
    vector<int> cnt(26);
    for(auto p:a)
        cnt[p-'a']++;
    for(auto p:b)
        cnt[p-'a']--;
    int ans=0;
    for(auto p:cnt)
        ans+=abs(p);
    return ans;
}
char koji(string a,string b){
    vector<int> cnt(26);
    for(auto p:a)
        cnt[p-'a']++;
    for(auto p:b)
        cnt[p-'a']--;
    char c;
    for(int i=0;i<26;i++)
        if(cnt[i]!=0)
            c='a'+i;
    return c;
}
int n;
vector<string> svi,l,r;
void ok(string ok){
    //cout << ok << endl;
    assert(ok.size()==n);
    vector<string> sv,le,ri;
    for(int i=0;i<n;i++){
        string tr;
        for(int j=i;j<n;j++){
            tr+=ok[j];
            sv.pb(tr);
        }
    }
    for(auto &p:sv)
        sort(all(p));
    sort(all(sv));

    for(int i=0;i<limit;i++){
        string tr;
        for(int j=i;j<limit;j++){
            tr+=ok[j];
            le.pb(tr);
        }
    }
    for(auto &p:le)
        sort(all(p));
    sort(all(le));

    for(int i=limit;i<n;i++){
        string tr;
        for(int j=i;j<n;j++){
            tr+=ok[j];
            ri.pb(tr);
        }
    }
    for(auto &p:ri)
        sort(all(p));
    sort(all(ri));

    if(sv==svi&&l==le&&r==ri)
    {
        //cout << l << endl << endl << endl << le << endl;
        cout << "! " << ok << endl;
        fflush(stdout);
        exit(0);
    }
    return;
}
void testAll(string napravi){
    //cout << napravi << endl;
    ok(napravi);
    swap(napravi[limit],napravi[limit+1]);
    ok(napravi);
    swap(napravi[limit],napravi[limit+1]);
    swap(napravi[limit+1],napravi[limit+2]);
    ok(napravi);
    swap(napravi[limit+1],napravi[limit+2]);
    swap(napravi[limit],napravi[limit-1]);
    ok(napravi);
    swap(napravi[limit],napravi[limit-1]);
    reverse(all(napravi));
    ok(napravi);
    swap(napravi[limit],napravi[limit+1]);
    ok(napravi);
    swap(napravi[limit],napravi[limit+1]);
    swap(napravi[limit+1],napravi[limit+2]);
    ok(napravi);
    swap(napravi[limit+1],napravi[limit+2]);
    swap(napravi[limit],napravi[limit-1]);
    ok(napravi);
}
vector<multiset<string> > duz;
void solve(string napravi,int i){
    if(napravi.size()==n)
        testAll(napravi);
    int s=napravi.size(),d=i+1;
    multiset<string> backup=duz[i];
    int in=0;
    bool fail=0;
    for(int j=0;j<s-i;j++){
        string tr;
        for(int k=j;k<j+d;k++)
            tr+=napravi[k];
        sort(all(tr));
        if(backup.find(tr)==backup.end()){
            fail=1;
            break;
        }
        backup.erase(backup.find(tr));
    }
    if(fail)
        return;
    if(backup.size()==0)
        return;
    string napred,nazad;
    for(int j=0;j<i;j++)
        napred+=napravi[j];
    for(int j=s-1;j>=s-i;j--)
        nazad+=napravi[j];
    reverse(all(nazad));
    //cout << backup << napravi << endl;
    assert(backup.size()==1||backup.size()==2);
    if(backup.size()==1){
        string tr=*backup.begin();
        if(diff(napred,tr)==1){
            napravi=koji(napred,tr)+napravi;
            if(napravi.size()==n)
                testAll(napravi);
            else
                solve(napravi,i+1);
            napravi=napravi.substr(1,napravi.size()-1);
        }
        if(diff(nazad,tr)==1){
            napravi=napravi+koji(nazad,tr);
            if(napravi.size()==n)
                testAll(napravi);
            else
                solve(napravi,i+1);
        }
        return;
    }
    if(backup.size()==2){
        string prvi=*backup.begin();
        backup.erase(backup.begin());
        string drugi=*backup.begin();
        if(diff(prvi,napred)==1&&diff(drugi,nazad)==1){
            napravi=koji(napred,prvi)+napravi+koji(drugi,nazad);
            solve(napravi,i+1);
            napravi=napravi.substr(1,napravi.size()-2);
        }
        if(diff(prvi,nazad)==1&&diff(drugi,napred)==1){
            napravi=koji(napred,drugi)+napravi+koji(prvi,nazad);
            solve(napravi,i+1);
        }
    }
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
    //cin >> mytest;
    n=mytest.size();
    scanf("%i",&n);
    if(n<=3){
        string a;
        for(int i=1;i<=n;i++){
            printf("? %i %i\n",i,i);
            fflush(stdout);
            string b;
            cin >> b;
            a+=b;
        }
        cout << "! " << a << endl;
        return 0;
    }
    svi=ask(1,n);
    /*bool ima=0;
    for(auto p:svi)
        if(p=="z")
            ima=1;
    if(n==52&&ima)*/
        limit=n/2-1;
    /*else
        limit=n/2;*/
    l=ask(1,limit),r=ask(limit+1,n);
    map<string,int> cnt;
    for(auto p:svi)
        cnt[p]++;
    for(auto p:l)
        cnt[p]--;
    for(auto p:r)
        cnt[p]--;
    duz.resize(n);
    for(auto p:cnt)
        while(p.s!=0)
            duz[p.f.size()-1].insert(p.f),p.s=abs(p.s)-1;
    string napravi=*duz[1].begin();
    solve(napravi,2);
    assert(0);
    return 0;
}