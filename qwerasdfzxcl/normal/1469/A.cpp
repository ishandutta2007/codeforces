#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
char input[200];

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%s", input);
        int i=0;
        while(input[i]!=0){
            i++;
        }
        if (i%2) printf("NO\n");
        else{
            int i=0, val1=0, val2=0;
            bool test=1;
            while(input[i]){
                if (input[i]=='?') val2++;
                else if (input[i]=='(') val1++;
                else{
                    if (val1>0) val1--;
                    else if (val2>0) val2--;
                    else{
                        test=0;
                        break;
                    }
                }
                i++;
            }
            i--;
            val1=0, val2=0;
            while(i>=0){
                if (input[i]=='?') val2++;
                else if (input[i]==')') val1++;
                else{
                    if (val1>0) val1--;
                    else if (val2>0) val2--;
                    else{
                        test=0;
                        break;
                    }
                }
                i--;
            }
            if (test) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}