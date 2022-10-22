#include <bits/stdc++.h>
using namespace std;

int n;
int arr[200000];
int le[200000];
int ri[200000];
typedef pair<int,int> P;
int val[200001];
vector<P> vec;
vector<P> v;

int main() {
    scanf("%d",&n);
    memset(le,-1,sizeof(le));
    memset(ri,-1,sizeof(ri));
    memset(val,-1,sizeof(val));
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
        arr[i]--;
        if (le[arr[i]]==-1) {
            le[arr[i]]=i;
        }
        ri[arr[i]]=i;
    }
    for(int i=0;i<n;i++) {
        if (le[i]!=ri[i]) {
            vec.push_back(P(le[i],ri[i]));
        }
    }
    sort(vec.begin(),vec.end());
    int mx=-1;
    for(int i=0;i<vec.size();i++) {
        if (vec[i].second>mx) {
            v.push_back(vec[i]);
            mx=vec[i].second;
        }
    }
    int pr=-1;
    int ret=0;
    for(int i=0;i<v.size();i++) {
        if (i+1==v.size()||v[i].second<v[i+1].first) {
            int len=v[i].second-v[pr+1].first+1;
            int now=pr+1;
            int d=0;
            for(int j=pr+1;j<=i;j++) {
                if (pr+1==i) {
                    break;
                }
                if (j==i||v[j+1].first>v[now].second) {
                    now=j;
                    d++;
                }
            }
            len-=d+2;
            ret+=len;
            pr=i;
        }
    }
    printf("%d",ret);
}