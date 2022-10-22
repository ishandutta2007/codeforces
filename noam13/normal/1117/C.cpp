#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ii pair<int,int>
#define x first
#define y second
#define abs(x) ((x>0)?(x):(-x))
#define all(x) x.begin(), x.end()
#define chkmax(a,b) (a=max(a,b))
#define chkmin(a,b) (a=min(a,b))
using namespace std;
#define MAXN 501
int INFI=1e18;
int x,y,n;
string s;
bool good(int step){
    int dx=0,dy=0;
    char c;
    if (step>=n){
        for(int i=0;i<n;i++){
            c=s[i%n];
            if (c=='U') dy++;
            if (c=='D') dy--;
            if (c=='L') dx--;
            if (c=='R') dx++;
        }
        dx*=(step/n);
        dy*=(step/n);
    }
    for(int i=0;i<step%n;i++){
        c=s[i%n];
        if (c=='U') dy++;
        if (c=='D') dy--;
        if (c=='L') dx--;
        if (c=='R') dx++;
    }
    //out << dx <<"-"<<dy<<": "<<x<<"_"<<y<<":"<<step<<endl;
    dx=x-dx;dy=y-dy;
    if (dx<0) dx=-dx;
    if (dy<0) dy=-dy;
    return (dx+dy<=step);
} 
int32_t main(){
    int a,b;
    cin >>x >>y>>a>>b;x=a-x;y=b-y;
    cin>>n;
    cin>>s;
    int l=0,r=INFI;
    int mid;
    while(l+1<r){
        mid=(l+r)/2;
        //cout << l <<"-"<<r<<"_"<<mid<<endl;
        if (good(mid)){
            r=mid;
        }
        else{
            l=mid;
        }
    }
    if (r==INFI) cout<<-1<<endl;
    else cout <<r <<endl;
    return 0;
}