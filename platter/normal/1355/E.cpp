#include <bits/stdc++.h>
using namespace std;

typedef pair<long long,long long> P;
P h[100000];
const long long INF=3e18;
map<int,int> mp;

int main(void) {
    int n;
    long long a,r,m;
    scanf("%d %lld %lld %lld\n",&n,&a,&r,&m);
    for(int i=0;i<n;i++) {
        scanf("%lld",&h[i].first);
        mp[h[i].first]++;
    }
    int cnt=0;
    for(auto curr:mp) {
        h[cnt++]=P(curr.first,curr.second);
    }
    int total=n;
    n=cnt;
    if (m>=a+r) {
        long long ret=INF;
        long long up=0;
        long long down=0;
        for(int i=0;i<n;i++) {
            up+=h[i].second*(h[i].first-h[0].first);
        }
        ret=r*up+a*down;
        int sum=h[0].second;
        for(int i=1;i<n;i++) {
            up-=(h[i].first-h[i-1].first)*(total-sum);
            down+=(h[i].first-h[i-1].first)*sum;
            ret=min(ret,r*up+a*down);
            sum+=h[i].second;
        }
        printf("%lld",ret);
        return 0;
    }
    long long ret=INF;
    long long up=0;
    long long down=0;
    for(int i=0;i<n;i++) {
        up+=h[i].second*(h[i].first-h[0].first);
    }
    ret=min(ret,r*up+(m-r)*down);
    int sum=h[0].second;
    for(int i=1;i<n;i++) {
        up-=(h[i].first-h[i-1].first)*(total-sum);
        down+=(h[i].first-h[i-1].first)*sum;
        if (up<down) {
            up+=(h[i].first-h[i-1].first)*(total-sum);
            down-=(h[i].first-h[i-1].first)*sum;
            long long diff=(up-down)/total;
            up-=diff*(total-sum);
            down+=diff*sum;
            ret=min(ret,r*up+(m-r)*down);
            break;
        }
        ret=min(ret,r*up+(m-r)*down);
        sum+=h[i].second;
    }
    up=0;
    down=0;
    sum=h[n-1].second;
    for(int i=0;i<n;i++) {
        down+=h[i].second*(h[n-1].first-h[i].first);
    }
    ret=min(ret,(m-a)*up+a*down);
    for(int i=n-2;i>=0;i--) {
        up+=(h[i+1].first-h[i].first)*sum;
        down-=(h[i+1].first-h[i].first)*(total-sum);
        if (up>down) {
            up-=(h[i+1].first-h[i].first)*sum;
            down+=(h[i+1].first-h[i].first)*(total-sum);
            long long diff=(down-up)/total;
            up+=diff*sum;
            down-=diff*(total-sum);
            ret=min(ret,(m-a)*up+a*down);
            break;
        }
        ret=min(ret,(m-a)*up+a*down);
        sum+=h[i].second;
    }
    printf("%lld",ret);
}