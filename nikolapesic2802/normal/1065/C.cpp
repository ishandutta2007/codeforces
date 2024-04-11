#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;
const int m=2*1e5+5;
int main()
{
    int n,k;
    scanf("%i %i",&n,&k);
    set<int> visine;
    vector<int> broj(m);
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        broj[a]++;
        visine.insert(a);
    }
    set<int>::iterator it=visine.end();
    int dokle=*visine.begin();
    it--;
    int poc=*it;
    int br=0;
    int cnt=0;
    int i=poc;
    while(i>dokle)
    {
        br+=broj[i];
        i--;
        ll sl=(ll)2*br+broj[i];
        //printf("Broj:%i sl:%lld %i\n",br,sl,i);
        while(sl<=(ll)k&&it!=visine.begin())
        {
            br+=broj[i];
            i--;
            if(i==-1)
            {
                break;
            }
            //printf("%i\n",*it);
            sl+=(ll)br+broj[i];
            //printf("Sl:%lld\n",sl);
        }
        assert(br<=n);
        cnt++;
    }
    printf("%i\n",cnt);
    return 0;
}