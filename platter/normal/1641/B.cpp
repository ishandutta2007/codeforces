#include <bits/stdc++.h>
using namespace std;

int n;
int pl=0;
int arr[501];
vector<int> ret;
typedef pair<int,int> P;
vector<P> vec;

void rotate(int l,int r) {
    for(int i=0;i<=r-l;i++) {
        vec.push_back(P(pl+r+i,arr[l+i]));
    }
    ret.push_back((r-l+1)*2);
    pl+=(r-l+1)*2;
    while (l<r) {
        swap(arr[l],arr[r]);
        l++;
        r--;
    }
}

int main() {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        scanf("%d",&n);
        set<int> s;
        vec.clear();
        ret.clear();
        pl=0;
        for(int i=1;i<=n;i++) {
            scanf("%d",&arr[i]);
            if (s.find(arr[i])!=s.end()) {
                s.erase(arr[i]);
            }
            else {
                s.insert(arr[i]);
            }
        }
        if (!s.empty()) {
            printf("-1\n");
            continue;
        }
        for(int i=1;i<=n;i+=2) {
            int pos=-1;
            for(int j=i+1;j<=n;j++) {
                if (arr[i]==arr[j]) {
                    pos=j;
                    break;
                }
            }
            if (pos==i+1) {
                ret.push_back(2);
                continue;
            }
            rotate(i,pos-1);
            rotate(i,pos);
            ret.push_back(2);
        }
        printf("%d\n",vec.size());
        for(int i=0;i<vec.size();i++) {
            printf("%d %d\n",vec[i].first,vec[i].second);
        }
        printf("%d\n",ret.size());
        for(int i=0;i<ret.size();i++) {
            printf("%d ",ret[i]);
        }
        printf("\n");
    }
    return 0;
}