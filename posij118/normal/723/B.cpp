#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, a, b, amax, c;
    b=0;
    a=0;
    amax=0;
    c=0;
    cin >> n;
    string s;
    cin >> s;

    for(int i=0; i<n; i++){

        if((s[i]==')' || s[i]=='_') && b>0 ){
                if(s[i-1]!=')' && s[i-1]!='(' && s[i-1]!='_'){
                    c++;
                }
                }
        if(s[i]=='(') b++;
        if(s[i]==')') b--;
        if(s[i]==')' || s[i]=='(' || s[i]=='_') a=0;
        else if(b==0) a++;
        amax=max(a, amax);
    }

    cout << amax << " " << c;
}