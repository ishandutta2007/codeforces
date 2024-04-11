#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s,s2;
    cin >> s;
    cin >> s2;
    int l1 = s.size();
    int l2 = s2.size();
    l1--;
    l2--;
    int cnt=0;
    while(l1>=0&&l2>=0)
    {
        if(s[l1]==s2[l2])
        {
            //printf("isto %i %i\n",l1,l2);
            cnt++;
        }
        else
        {
            break;
        }
        l1--;
        l2--;
    }
    cnt*=2;
    printf("%i",s.size()+s2.size()-cnt);

    return 0;
}