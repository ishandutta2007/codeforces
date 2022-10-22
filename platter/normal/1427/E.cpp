#include<bits/stdc++.h>
using namespace std;

typedef pair<long long,long long> P;
typedef pair<P,int> Pi; //^:0 +:1
vector<Pi> ret;

void func(long long x,long long t) {
    long long val=0;
    while (t!=0) {
        if (t%2==1) {
            ret.push_back(Pi(P(val,x),1));
            val+=x;
        }
        ret.push_back(Pi(P(x,x),1));
        x*=2;
        t/=2;
    }
}

int main(void) {
    long long x;
    scanf("%lld",&x);
    ret.push_back(Pi(P(x,x),0));
    int bit=20;
    for(int i=19;i>=0;i--) {
        if (x&(1<<i)) {
            bit=i;
            break;
        }
    }
    for(int i=0;i<bit;i++) {
        ret.push_back(Pi(P(x<<i,x<<i),1));
    }
    ret.push_back(Pi(P(x<<bit,x),0));
    long long y=((x<<bit)^x);
    long long val=(1LL<<60);
    for(int i=0;i<x;i++) {
        if ((val-y*i)%x==0) {
            func(x,(val-y*i)/x);
            func(y,i);
            ret.push_back(Pi(P(val-y*i,y*i),1));
            break;
        }
    }
    for(int i=59;i>=0;i--) {
        long long temp=x;
        for(int j=19;j>i;j--) {
            if (temp&(1<<j)) {
                ret.push_back(Pi(P(temp,(1<<j)),0));
                temp-=(1<<j);
            }
        }
        for(int j=0;j<i;j++) {
            ret.push_back(Pi(P(temp,temp),1));
            temp*=2;
            if (temp&(1LL<<(i+1))) {
                ret.push_back(Pi(P(temp,(1LL<<(i+1))),0));
                temp-=(1LL<<(i+1));
            }
        }
    }
    printf("%d\n",ret.size());
    for(int i=0;i<ret.size();i++) {
        printf("%lld %c %lld\n",ret[i].first.first,ret[i].second?'+':'^',ret[i].first.second);
    }
}