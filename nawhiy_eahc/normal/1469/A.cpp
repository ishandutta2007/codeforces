#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        string s;
        cin >> s;
        stack<int> st;
        int n = s.size();
        if(n%2){
            printf("no\n");
            continue;
        }
        bool b = true;
        int lef = 0, rig = 0;
        for(int i = 0;i<n;i++){
            if(s[i] == ')') lef++;
            else lef--;
            if(lef > 0) break;
        }
        for(int i = n-1;i>=0;i--){
            if(s[i] == '(') rig++;
            else rig--;
            if(rig > 0) break;
        }

        if(lef > 0 || rig > 0) printf("no\n");
        else printf("yes\n");
    }
}