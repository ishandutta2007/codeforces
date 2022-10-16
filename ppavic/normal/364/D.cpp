#include <cstdio>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

const int N = 1e6 + 500;
const int K = 10;

int n;
ll a[N];

vector < ll > sol;

ll gcd(ll A, ll B){
    if(!B) return A;
    return gcd(B, A % B);
}

ll myrand(){
    return ((ll)rand()<<16) | rand();
}

int cost(ll x){
    int cnt = 0;
    for(int i = 0;i<n;i++)
        cnt += !(a[i]%x);
    return cnt;
}

int main(){
    srand(time(NULL) + 1);
    scanf("%d",&n);
    for(int i = 0;i<n;i++)
        scanf("%I64d",a+i);
    ll fin = -1,mks = 0;
    for(int l = 0;l<K;l++){
        vector < ll > dij1,dij2,cnt;
        ll cur = a[myrand() % (ll)n];
        for(ll i = 1;i*i<=cur;i++){
            if(cur%i) continue;
            dij1.push_back(i);
            dij2.push_back(cur / i);
        }
        if(dij1.back() == dij2.back())
            dij2.pop_back();
        reverse(dij2.begin(),dij2.end());
        dij1.insert(dij1.end(),dij2.begin(),dij2.end());
        vector < ll > v3;
        for(int i = 0;i<n;i++){
            v3.push_back(gcd(cur,a[i]));
        }
        for(int i = 0;i<dij1.size();i++)
            cnt.push_back(0);
        sort(v3.begin(),v3.end());
        int j = 0;
        for(int i = 0;i<cnt.size();i++){
            while(j < n && v3[j] == dij1[i]){cnt[i]++;j++;}
        }
        for(int i = 0;i<dij1.size();i++){
            int cnt2 = 0;
            for(int j = i;j<dij1.size();j++)
                if(dij1[j] % dij1[i] == 0)
                    cnt2 += cnt[j];
            if(cnt2 >= (n + 1) / 2 && dij1[i] > fin)
                fin = dij1[i];
        }
    }
    printf("%I64d\n",fin);
}