#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int curr = 0;
        for(int i=0;i<n;i++){
            if(s[i] - '0' + 1 != curr){
                printf("1");
                curr = s[i] - '0' + 1;
            }
            else{
                printf("0");
                curr = s[i] - '0';
            }
        }
        printf("\n");
    }
}