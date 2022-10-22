#include <iostream>
#include <vector>

using namespace std;
int a[200002];
int cnt[200002];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n, current;
        vector<int> v;
        scanf("%d", &n);
        for(int i=1;i<=n;i++){
            scanf("%d", &a[i]);
            cnt[i] = 0;
        }
        current = 0;
        for(int i=1;i<=n;i++){
            if(a[i]!=current){
                cnt[a[i]]++;
                current = a[i];
                v.push_back(a[i]);
            }
        }
        cnt[a[1]]--;
        cnt[a[n]]--;
        int m = 10000000;
        for(int i : v){
            m = min(cnt[i], m);
        }
        printf("%d\n", m+1);
    }
}