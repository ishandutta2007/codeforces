#include <bits/stdc++.h>
using namespace std;

int arr[250000];

int main() {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int n;
        scanf("%d",&n);
        vector<int> v;
        int cnt0=0;
        for(int i=0;i<n;i++) {
            int x;
            scanf("%d",&x);
            if (x==0) {
                cnt0++;
                continue;
            }
            v.push_back(x);
        }
if (v.empty()) {
printf("0\n");
continue;
}
int prv=v.size();
        v.erase(unique(v.begin(),v.end()),v.end());
prv-=v.size();
        while (v.size()>1) {
            int pr=-1;
            vector<int> save;
            for(int i=0;i<v.size();i++) {
                save.push_back(v[i]);
            }
            v.clear();
            for(int i=1;i<save.size();i++) {
                v.push_back(save[i]-save[i-1]);
            }
            if (cnt0!=0) {
                v.push_back(save[0]);
                cnt0--;
            }
int nv=v.size();
            sort(v.begin(),v.end());
            v.erase(unique(v.begin(),v.end()),v.end());
nv-=v.size();
cnt0+=prv;
prv=nv;
        }
if (v.empty()) {printf("0\n"); continue;}
if (prv!=0&&cnt0==0) {printf("0\n");continue;}
        printf("%d\n",v[0]);
    }
    return 0;
}