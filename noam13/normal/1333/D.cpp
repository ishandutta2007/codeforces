#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvvvi vector<vvvi>
#define vvvvvi vector<vvvvi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e18, MAXN = 3e3+2, MAXK = 3e6+2;


int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,k; cin>>n>>k;
    string s; cin>>s;
    bool b[MAXN]; loop(i,0,n) b[i]=(s[i]=='R');
    vi ans[MAXN];
    int last = -1;
    vi ev, next; loop(i,0,n-1) ev.pb(i);
    int times[MAXN]; 
    loop(i,0,n) times[i]=-1;
    times[n-1]=INF;
    loop(j,0,n){
        next.clear();
        for(int i:ev){
            if (b[i] && !b[i+1]) {
                ans[j].pb(i+1); 
                if (i && times[i-1]<j) next.pb(i-1), times[i-1]=j;
                if (times[i+1]<j) next.pb(i+1), times[i+1]=j;
            }
        }
        if (!ans[j].size()) break;
        for(int &x:ans[j]) swap(b[x], b[x-1]);
        last = j;
        ev = next;
    }
    if (last>=k) return cout<<-1<<endl,0;
    int sum = 0;
    loop(i,0,last+1) sum+=ans[i].size();
    if (sum<k) return cout<<-1<<endl,0;
    int cur = 0;
    n = last;
    loop(i,0,k){
        while (cur<n && !ans[cur].size()) {
            cur++;
        }
        //if (cur>=n) return cout<<-1<<endl,0;
        int left = k-i, leftfrom = n - cur;
        int spare = sum-(k-i)+1, sz = ans[cur].size();
        int amt = min(spare,sz);
        cout<<amt<<" ";
        loop(x,0,amt) {
            cout<<ans[cur].back()<<" "; ans[cur].pop_back();
        }
        cout<<"\n";
        sum-=amt;
        /*else{
            cout<<1<<" "<<ans[cur].back()<<"\n";
            ans[cur].pop_back();
        }*/
    }
    return 0;
}
/*
color a
cls
g++ d.cpp -o c & c
4 3
RLRL




*/