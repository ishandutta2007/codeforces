#include <bits/stdc++.h>
using namespace std;
 
vector<int> prime;
const long long bil=1000000000;
 
bool isprime(int x) {
    if (x==1) {
        return false;
    }
    for(int i=2;i*i<=x;i++) {
        if (x%i==0) {
            return false;
        }
    }
    return true;
}
 
int main(void) {
    int tc;
    scanf("%d",&tc);
    for(int i=2;i<=1000;i++) {
        if (isprime(i)) {
            prime.push_back(i);
        }
    }
    for(int t=0;t<tc;t++) {
        long long val=1;
        bool flag=false;
        for(int i=0;i<=(prime.size()-1)/6;i++) {
            if (val<=3&&1LL*prime[i*6]*prime[i*6]*prime[i*6]*prime[i*6]>bil) {
                flag=true;
                printf("! %d\n",val==1?8:9);
                fflush(stdout);
                break;
            }
            if (val*prime[i*6]*prime[i*6]*prime[i*6]>bil) {
                break;
            }
            long long x=1;
            for(int j=i*6;j<min((int)prime.size(),i*6+6);j++) {
                x*=prime[j];
                if (j==0) {
                    x*=2;
                }
                if (j==1) {
                    x*=3;
                }
            }
            printf("? %lld\n",x);
            fflush(stdout);
            long long got;
            scanf("%lld",&got);
            val*=got;
        }
        if (flag) {
            continue;
        }
        vector<int> v;
        for(int i=0;i<prime.size();i++) {
            if (val%prime[i]==0) {
                v.push_back(prime[i]);
            }
        }
        int ret=1;
        for(int i=0;i<=((int)v.size()-1)/2;i++) {
            if (i*2+1==v.size()) {
                long long x=1;
                while (x*v[i*2]<=bil) {
                    x*=v[i*2];
                }
                printf("? %lld\n",x);
                fflush(stdout);
                scanf("%lld",&x);
                int cnt=0;
                while (x!=1) {
                    x/=v[i*2];
                    cnt++;
                }
                ret*=cnt+1;
                break;
            }
            long long one=1;
            long long two=1;
            while (one*v[i*2]<=bil) {
                one*=v[i*2];
            }
            while (two*v[i*2+1]<=bil) {
                two*=v[i*2+1];
            }
            printf("? %lld\n",one*two);
            fflush(stdout);
            long long x;
            scanf("%lld",&x);
            one=1;
            two=1;
            while (x%v[i*2]==0) {
                x/=v[i*2];
                one++;
            }
            while (x%v[i*2+1]==0) {
                x/=v[i*2+1];
                two++;
            }
            ret*=one*two;
        }
        printf("! %d\n",ret*2);
        fflush(stdout);
    }
}