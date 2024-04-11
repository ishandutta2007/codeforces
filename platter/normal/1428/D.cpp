#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100000];
int pos[100000];
vector<int> v;
vector<int> v2;
int two[100000];
typedef pair<int,int> P;
vector<P> ret;
bool used[100000];

int main(void) {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
        if (arr[i]==1) {
            v.push_back(i);
        }
        if (arr[i]!=0) {
            v2.push_back(i);
        }
    }
    int ind=0;
    for(int i=0;i<n;i++) {
        if (arr[i]==3) {
            while (ind<v2.size()&&v2[ind]<=i) {
                ind++;
            }
            if (ind==v2.size()) {
                printf("-1");
                return 0;
            }
            two[i]=v2[ind++];
            used[two[i]]=true;
        }
    }
    ind=0;
    for(int i=0;i<n;i++) {
        if (arr[i]==2) {
            while (ind<v.size()&&(v[ind]<=i||used[v[ind]])) {
                ind++;
            }
            if (ind==v.size()) {
                printf("-1");
                return 0;
            }
            two[i]=v[ind++];
        }
    }
    for(int i=0;i<n;i++) {
        if (pos[i]!=0) {
            continue;
        }
        if (arr[i]==0) {
            continue;
        }
        ret.push_back(P(i+1,i+1));
        if (arr[i]==3) {
            ret.push_back(P(two[i]+1,i+1));
        }
        if (arr[i]==2) {
            pos[two[i]]=-1;
            ret.push_back(P(two[i]+1,i+1));
        }
    }
    printf("%d\n",ret.size());
    for(int i=0;i<ret.size();i++) {
        printf("%d %d\n",ret[i].second,ret[i].first);
    }
}