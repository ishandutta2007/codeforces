#include <bits/stdc++.h>
using namespace std;

long long arr[200001];
long long val[200001][11];
priority_queue<long long> pq[11];
priority_queue<long long> er[11];
bool isp[200001];
vector<int> v;

long long cal() {
    long long ret=0;
    for(int i=0;i<v.size();i++) {
        while (!er[i].empty()&&er[i].top()==pq[i].top()) {
            pq[i].pop();
            er[i].pop();
        }
        ret=max(ret,pq[i].top()*v[i]);
    }
    return ret;
}

int main() {
    for(int i=2;i<=200000;i++) {
        isp[i]=true;
    }
    for(int i=2;i<=200000;i++) {
        if (isp[i]) {
            for(int j=i*2;j<=200000;j+=i) {
                isp[j]=false;
            }
        }
    }
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n,q;
        scanf("%d %d",&n,&q);
        for(int i=0;i<n;i++) {
            scanf("%lld",&arr[i]);
        }
        int ind=2;
        int vl=n;
        v.clear();
        while (ind*ind<=n) {
            if (isp[ind]&&n%ind==0) {
                v.push_back(ind);
                while (vl%ind==0) {
                    vl/=ind;
                }
            }
            ind++;
        }
        if (vl!=1) {
            v.push_back(vl);
        }
for(int i=0;i<v.size();i++) v[i]=n/v[i];
        for(int i=0;i<n;i++) {
            for(int j=0;j<v.size();j++) {
                val[i][j]=0;
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<v.size();j++) {
                val[i%v[j]][j]+=arr[i];
            }
        }
        for(int j=0;j<v.size();j++) {
            for(int i=0;i<v[j];i++) {
                pq[j].push(val[i][j]);
            }
        }
        printf("%lld\n",cal());
        for(int i=0;i<q;i++) {
            int ind,x;
            scanf("%d %d",&ind,&x);
ind--;
            for(int j=0;j<v.size();j++) {
                er[j].push(val[ind%v[j]][j]);
                val[ind%v[j]][j]-=arr[ind];
                val[ind%v[j]][j]+=x;
                pq[j].push(val[ind%v[j]][j]);
            }
arr[ind]=x;
            printf("%lld\n",cal());
        }
        for(int i=0;i<v.size();i++) {
while (!pq[i].empty()) pq[i].pop();
while (!er[i].empty()) er[i].pop();
        }
    }
}