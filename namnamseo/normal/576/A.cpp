#include <cstdio>
#include <vector>

bool prime(int x)
{
    if(x==1) return 0;
    int i;
    for(i=2;i*i<=x;++i) if(x%i==0) return 0;
    return 1;
}

using namespace std;
vector<int> v;

int main()
{
    int n;
    scanf("%d",&n);
    int i,j;
    for(i=2;i<=n;++i){
        if(prime(i)){
            for(j=i;j<=n;j*=i){
                v.push_back(j);
            }
        }
    }
    printf("%u\n",j=v.size());
    for(i=0;i<j;++i) printf("%d ",v[i]);
    return 0;
}