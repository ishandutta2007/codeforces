#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;
int broj[40000];
int main()
{
    int a;
    scanf("%i",&a);
    string s;
    cin >> s;
    int broj1=0;
    for(int i=0;i<s.size();i++)
    {
        int tr=0;
        for(int j=i;j<s.size();j++)
        {
            //printf("%i ",(s[i]-'0')*(s[j]-'0'));
            tr+=s[j]-'0';
            //printf("Dodajem %i\n",tr);
            broj1++;
            broj[tr]++;
        }
        //printf("\n");
    }
    if(a==0)
    {
        int zero=broj[0],non_zero=broj1-broj[0];
        printf("%lld\n",(ll)(zero+non_zero)*(ll)(zero+non_zero)-(ll)non_zero*non_zero);
        return 0;
    }
    ll sum=0;
    for(int i=1;i<40000;i++)
    {
        if(a%i==0&&a/i<40000)
        {
            sum+=(ll)broj[i]*(ll)broj[a/i];
        }
    }
    printf("%lld\n",sum);
    return 0;
}