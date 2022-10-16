#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i",&n);
    for(int i=0;i<n;i++)
    {
        char niz[101];
        scanf("%s",niz);
        string s=niz;
        if(s.size()>10)
        {
            string s2;
            s2+=s[0];
            s2+=to_string(s.size()-2);
            s2+=s[s.size()-1];
            s=s2;
        }
        cout << s <<endl;
    }
    return 0;
}