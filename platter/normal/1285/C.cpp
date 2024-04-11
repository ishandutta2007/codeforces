#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<long long> v;
int vn;
vector<long long> vl;

void put(int ind,long long val) {
    if (ind==vn) {
        vl.push_back(val);
        return;
    }
    put(ind+1,val);
    put(ind+1,val*v[ind]);
}

int main(void) {
    long long x;
    scanf("%lld",&x);
    if (x==1) {
        printf("1 1");
        return 0;
    }
    for(long long i=2;i*i<=x;i++) {
        long long k=1;
        while (x%i==0) {
            k*=i;
            x/=i;
        }
        if (k!=1) {
            v.push_back(k);
        }
    }
    if (x!=1) {
        v.push_back(x);
    }
    vn=v.size();
    put(0,1);
    int vln=vl.size();
    sort(vl.begin(),vl.end());
    printf("%lld %lld",vl[vln/2-1],vl[vln/2]);
    return 0;
}