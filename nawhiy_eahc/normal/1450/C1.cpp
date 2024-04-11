#include <iostream>

using namespace std;
char ttt[400][400];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        for(int i=0;i<=n+6;i++){
            for(int j=0;j<=n+6;j++){
                ttt[i][j] = '.';
            }
        }
        for(int i=0;i<n;i++){
            string s;
            cin >> s;
            for(int j=0;j<n;j++){
                ttt[i][j] = s[j];
            }
        }
        int cnt[3];
        for(int mod=0;mod<=2;mod++){
            cnt[mod] = 0;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if((i+j)%3==mod && ttt[i][j] == 'X') cnt[mod]++;
                }
            }
        }
        int ansmod = (cnt[0]>cnt[1])?((cnt[1]>cnt[2])?2:1):((cnt[0]>cnt[2])?2:0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if((i+j)%3==ansmod && ttt[i][j] == 'X') printf("O");
                else printf("%c", ttt[i][j]);
            }
            printf("\n");
        }
    }
}