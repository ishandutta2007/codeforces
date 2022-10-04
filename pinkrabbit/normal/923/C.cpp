#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
using namespace std;

int n;
int a[300001];
multiset<int> b;

int main(){
    int x;
    scanf("%d",&n);
    F(i,1,n) scanf("%d",a+i);
    F(i,1,n) scanf("%d",&x), b.insert(x);
    F(i,1,n){
        int now=0;
        dF(j,29,0){
            if((a[i]>>j)&1){
                now+=1<<j;
                multiset<int>::iterator it1=b.lower_bound(now), it2=b.lower_bound(now+(1<<j));
                if(it1==it2)
                    now-=1<<j;
            }
            else{
                multiset<int>::iterator it1=b.lower_bound(now), it2=b.lower_bound(now+(1<<j));
                if(it1==it2)
                    now+=1<<j;
            }
        }
        b.erase(b.lower_bound(now));
        printf("%d ",a[i]^now);
    }
    return 0;
}