#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define pb push_back

using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set; ///find_by_order(),order_of_key()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<string> in(n),out(n);
    for(int i=0;i<n;i++)
    {
        cin >> in[i];
    }
    for(int i=0;i<n;i++)
    {
        cin >> out[i];
    }
    vector<int> ima(n);
    vector<int> prvi1(n);
    int maxx=-1,gde,poz;
    for(int i=0;i<n;i++)
    {
        int s=in[i].size();
        int first=-1;
        for(int j=0;j<s;j++)
        {
            if(in[i][j]!=out[i][j])
            {
                ima[i]=1;
                if(first==-1)
                {
                    first=j;
                }
                prvi1[i]=first;
                int diff=j-first+1;
                if(diff>maxx)
                {
                    maxx=diff;
                    gde=i;
                    poz=first;
                }
            }
        }
    }
    assert(maxx>0);
    ll h1=0,h2=0;
    ll mod=9223372036854839;
    for(int i=0;i<maxx;i++)
    {
        h1=((ll)h1*27+in[gde][poz+i]-'a'+1)%mod;
        h2=((ll)h2*27+out[gde][poz+i]-'a'+1)%mod;
    }
    ll oduzimanje=1;
    for(int i=0;i<maxx;i++)
    {
        oduzimanje=((ll)oduzimanje*27)%mod;
    }
    vector<int> pocetak(n);
    pocetak[gde]=poz;
    for(int i=0;i<n;i++)
    {
        if(!ima[i])
            continue;
        if(in[i].size()<maxx)
        {
            printf("NO\n");
            return 0;
        }
        int pozi=0;
        ll prvi=0,drugi=0;
        for(int j=0;j<maxx;j++)
        {
            prvi=((ll)prvi*27+in[i][j]-'a'+1)%mod;
            drugi=((ll)drugi*27+out[i][j]-'a'+1)%mod;
        }
        for(int j=maxx;j<in[i].size();j++)
        {
            if(h1==prvi)
            {
                if(h2==drugi&&prvi1[i]<j)
                    break;
            }
            pozi++;
            prvi=((ll)prvi*27+in[i][j]-'a'+1)%mod;
            drugi=((ll)drugi*27+out[i][j]-'a'+1)%mod;
            prvi=((ll)prvi-(((ll)oduzimanje*(in[i][j-maxx]-'a'+1))%mod))%mod;
            if(prvi<0)
                prvi+=mod;
            assert(prvi>=0);
            drugi=((ll)drugi-(((ll)oduzimanje*(out[i][j-maxx]-'a'+1))%mod))%mod;
            if(drugi<0)
                drugi+=mod;
            assert(drugi>=0);
        }
        if(h1==prvi)
        {
            if(h2!=drugi)
            {
                printf("NO\n");
                return 0;
            }
            else
            {
                for(int k=0;k<in[i].size();k++)
                {
                    if(k<pozi||k>=pozi+maxx)
                    {
                        if(in[i][k]!=out[i][k])
                        {
                            printf("NO\n");
                            return 0;
                        }
                    }
                }
            }
        }
        else
        {
            printf("NO\n");
            return 0;
        }
        pocetak[i]=pozi;
    }
    ll dodavanje=oduzimanje;
    while(true)
    {
        if(poz==0)
            break;
        char before=in[gde][poz-1];
        char b2=out[gde][poz-1];
        bool test=true;
        for(int i=0;i<n;i++)
        {
            if(ima[i])
            {
                if(pocetak[i]==0)
                {
                    test=false;
                    break;
                }
                if(in[i][pocetak[i]-1]!=before||out[i][pocetak[i]-1]!=b2){
                    test=false;
                    break;
                }
            }
        }
        if(test)
        {
            h1=(h1+(ll)dodavanje*(in[gde][poz-1]-'a'+1))%mod;
            h2=(h2+(ll)dodavanje*(out[gde][poz-1]-'a'+1))%mod;
            for(int i=0;i<n;i++)
            {
                if(ima[i])
                {
                    pocetak[i]--;
                }
            }
            poz--;
            maxx++;
        }
        else
            break;
        dodavanje=((ll)dodavanje*27)%mod;
        oduzimanje=((ll)oduzimanje*27)%mod;
    }
    while(true)
    {
        if(poz+maxx-1==in[gde].size()-1)
            break;
        char before=in[gde][poz+maxx];
        char b2=out[gde][poz+maxx];
        bool test=true;
        for(int i=0;i<n;i++)
        {
            if(ima[i])
            {
                if(pocetak[i]+maxx-1==in[i].size()-1)
                {
                    test=false;
                    break;
                }
                if(in[i][pocetak[i]+maxx]!=before||out[i][pocetak[i]+maxx]!=b2){
                    test=false;
                    break;
                }
            }
        }
        if(test)
        {
            h1=((ll)h1*27+in[gde][poz+maxx]-'a'+1)%mod;
            h2=((ll)h2*27+out[gde][poz+maxx]-'a'+1)%mod;
            maxx++;
        }
        else
            break;
    }
    for(int i=0;i<n;i++)
    {
        if(in[i].size()<maxx)
        {
            continue;
        }
        int pozi=0;
        ll prvi=0,drugi=0;
        for(int j=0;j<maxx;j++)
        {
            prvi=((ll)prvi*27+in[i][j]-'a'+1)%mod;
            drugi=((ll)drugi*27+out[i][j]-'a'+1)%mod;
        }
        for(int j=maxx;j<in[i].size();j++)
        {
            if(h1==prvi)
            {
                break;
            }
            pozi++;
            prvi=((ll)prvi*27+in[i][j]-'a'+1)%mod;
            drugi=((ll)drugi*27+out[i][j]-'a'+1)%mod;
            prvi=((ll)prvi-(((ll)oduzimanje*(in[i][j-maxx]-'a'+1))%mod))%mod;
            if(prvi<0)
                prvi+=mod;
            drugi=((ll)drugi-(((ll)oduzimanje*(out[i][j-maxx]-'a'+1))%mod))%mod;
            if(drugi<0)
                drugi+=mod;
        }
        if(h1==prvi)
        {
            if(h2!=drugi)
            {
                printf("NO\n");
                return 0;
            }
            else
            {
                for(int k=0;k<in[i].size();k++)
                {
                    if(k<pozi||k>=pozi+maxx)
                    {
                        if(in[i][k]!=out[i][k])
                        {
                            printf("NO\n");
                            return 0;
                        }
                    }
                }
            }
        }

        else
        {
            continue;
        }
    }
    cout << "YES\n";
    cout << in[gde].substr(poz,maxx) << "\n";
    cout << out[gde].substr(poz,maxx) << "\n";
    return 0;
}