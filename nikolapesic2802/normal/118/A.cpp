#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;

int main()
{
    string s;
    cin >> s;
    for(int i=0;i<s.size();i++)
    {
        char c=s[i];
        if(c=='a'||c=='A'||c=='o'||c=='O'||c=='y'||c=='Y'||c=='e'||c=='E'||c=='u'||c=='U'||c=='i'||c=='I')
        {
        }
        else
        {
            printf(".");
            if(c>='a')
            {
                printf("%c",c);
            }
            else
            {
                printf("%c",c-'A'+'a');
            }
        }
    }
    return 0;
}