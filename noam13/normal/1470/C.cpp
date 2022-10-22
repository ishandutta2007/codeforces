#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 4e18, MOD = 1e9+7;

int n, q = 0;
int ask(int a){
    if (q++ == 1000) exit(1);
    a = (a%n+n)%n;
    cout<<"? "<<a+1<<endl;
    cin>>a;
    return a;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int k; cin>>n>>k;
    int ind = 0, s = 0;
    int v;
    while(1){
        v = ask(ind);
        if (v!=k) {
            if (v<k) ind++;
            else ind--;
            break;
        }
        ind += s;
        s++;
    }
    if (v<k){
        while(ask(ind)<k) ind++;
    }
    else{
        while(ask(ind)>k) ind--;
    }
    cout<<"! "<<(ind%n+n)%n+1<<endl;
    return 0;
}
/*
color a
cls
g++ c.cpp -o a & a
4 2 
*/