#include <iostream>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n, k;
        scanf("%d %d", &n, &k);
        int num[27];
        int num2[27];
        for(int i=1;i<=26;i++){
            num[i] = 0;
            num2[i] = 0;
        }
        string s, s2;
        cin >> s;
        cin >> s2;
        for(int i=0;i<n;i++){
            num[s[i]-'a'+1]++;
            num2[s2[i]-'a'+1]++;
        }
        bool result = true;
        for(int i=1;i<26;i++){
            if(num[i]>=num2[i] && (num[i]-num2[i])%k == 0){
                int temp = num[i]-num2[i];
                num[i] = num2[i];
                num[i+1] += temp;
            }
            else result = false;
        }

        if(result) printf("Yes\n");
        else printf("No\n");
    }
}