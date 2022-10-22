#include <bits/stdc++.h>

using namespace std;

int a[2002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=1;i<=2*n;i++){
            cin >> a[i];
        }
        sort(a + 1, a + 2*n + 1);

        int x = a[2*n]; int g = -1;

        for(int i=1;i<=2*n-1;i++){
            map<int, int> cnt;
            x = a[2*n];
            bool flag = true;
            for(int j=1;j<=2*n;j++){
                cnt[a[j]]++;
            }
            cnt[a[2*n]]--; cnt[a[i]]--;

            for(int j=2*n-1;j>=1;j--){
                while(cnt[a[j]] == 0 && j > 0){
                    j--;
                }
                if(j == 0) break;

                cnt[a[j]]--;
                if(cnt[x - a[j]] == 0){
                    flag = false;
                    break;
                }

                cnt[x-a[j]]--;
                x = a[j];
            }

            if(flag){
                g = i;
                break;
            }
        }

        if(g == -1) printf("NO\n");
        else{
            printf("YES\n");
            map<int, int> cnt;
            x = a[2*n];
            for(int j=1;j<=2*n;j++){
                cnt[a[j]]++;
            }
            cnt[a[2*n]]--; cnt[a[g]]--;
            printf("%d\n%d %d\n",a[2*n] + a[g], a[2*n], a[g]);

            for(int j=2*n-1;j>=1;j--){
                while(cnt[a[j]] == 0 && j > 0) j--;
                if(j == 0) break;

                cnt[x-a[j]]--; cnt[a[j]]--;
                printf("%d %d\n", x-a[j], a[j]);
                x = a[j];
            }
        }
    }
}