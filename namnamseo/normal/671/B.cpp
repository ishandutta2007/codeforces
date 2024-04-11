#include <cstdio>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
int n,k;
typedef pair<int,int> pp;

set<pp> s;

typedef long long ll;

int data[500010];

int lb, rb;

bool xMimanSonsai(int t){
    int i;
    ll sum=0;
    for(i=0;i<n;++i){
        if(t>=data[i]){
            sum += t-data[i];
        }
    }
    return sum > k;
}

bool xChogwaSonsai(int t){
    int i;
    ll sum=0;
    for(i=0;i<n;++i){
        if(t<=data[i]){
            sum += data[i]-t;
        }
    }
    return sum > k;
}

int main(){
    //freopen("input.txt", "r", stdin);
    
    scanf("%d%d",&n,&k);
    int i;
    ll s=0;
    for(i=0;i<n;++i) {
        scanf("%d",data+i);
        s+=data[i];
    }
    lb=s/n;
    rb=(s+n-1)/n;
    int minv, maxv;
    int l,r,m;
    
    l=0, r=lb+1;
    while(l+1<r){
        m=(l+r)/2;
        if(xMimanSonsai(m)) r=m;
        else l=m;
    }
    minv = l;
    
    l=rb-1, r=int(1e9)+1;
    while(l+1<r){
        m=(l+r)/2;
        if(xChogwaSonsai(m)) l=m;
        else r=m;
    }
    maxv = r;
    
    //printf("mv %d Mv %d\n",minv, maxv);
    
    printf("%d\n",maxv - minv);
    
    return 0;
}