#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mod 1000000007
#define reset(s,val) memset(s,val,sizeof(s))
#define eps 1e-9
#define pi acos(-1)
#define sqr(x) (x)*(x)
#define two(x) (1<<(x))

long long n,x,y;
pair<long long,long long> col[200005],row[200005];

int main( ){
    // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n;
    For(i,0,n){
        cin>>x>>y;
        col[i]={x,y};
        row[i]={y,x};
    }
    sort(col,col+n);
    sort(row,row+n);
    long long ans=0,cntr=1,cntc=1,off=0,cntoff=1;
    For(i,1,n) {
        if(col[i].first==col[i-1].first){
            ans+=cntr;
            cntr++;
        }
        else{
            cntr=1;
        }
        if(row[i].first==row[i-1].first){
            ans+=cntc;
            cntc++;
        }
        else{
            cntc=1;
        }if(col[i].first==col[i-1].first&&col[i].second==col[i-1].second){
            off+=cntoff;
            cntoff++;
        }else{
            cntoff=1;
        }
    }
    cout<<ans-off<<endl;
}