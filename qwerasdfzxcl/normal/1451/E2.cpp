#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
pair<int, int> xxor[100000]={make_pair(0, 0)};
int ans[100000]={0};

int main(){
    int n;
    scanf("%d", &n);
    xxor[0]=make_pair(0, 1);
    for (int i=2;i<=n;i++){
        printf("XOR 1 %d\n", i);
        fflush(stdout);
        scanf("%d", &xxor[i-1].first);
        xxor[i-1].second=i;
        ans[i-1]=xxor[i-1].first;
    }
    sort(xxor, xxor+n);
    bool test=0;
    int same1, same2, same3;
    for (int i=0;i<n-1;i++){
        if (xxor[i].first==xxor[i+1].first){
            test=1;
            same1=xxor[i].second;
            same2=xxor[i+1].second;
            same3=i;
            break;
        }
    }
    if (test){
        printf("AND %d %d\n", same1, same2);
        int tmp;
        fflush(stdout);
        scanf("%d", &tmp);
        for (int z=0;z<20;z++){
            int tmp1=1<<z;
            tmp1=tmp1&(tmp^xxor[same3].first);
            bool test2=(tmp1);
            if (test2){
                for (int i=0;i<n;i++) ans[i]=ans[i]^(1<<z);
            }
        }
        printf("! ");
        for (int i=0;i<n;i++) printf("%d ", ans[i]);
        fflush(stdout);
    }
    else{
        printf("AND %d %d\n", xxor[0].second, xxor[1].second);
        int tmp;
        fflush(stdout);
        scanf("%d", &tmp);
        for (int z=1;z<20;z++){
            int tmp1=1<<z;
            tmp1=tmp1&(tmp^0);
            bool test2=(tmp1);
            if (test2){
                for (int i=0;i<n;i++) ans[i]=ans[i]^(1<<z);
            }
        }
        printf("AND %d %d\n", xxor[0].second, xxor[n-2].second);
        fflush(stdout);
        scanf("%d", &tmp);
        int tmp1=1&(tmp^0);
        bool test2=(tmp1);
        if (test2){
            for (int i=0;i<n;i++) ans[i]=ans[i]^1;
        }
        printf("! ");
        for (int i=0;i<n;i++) printf("%d ", ans[i]);
        fflush(stdout);
    }
    return 0;
}