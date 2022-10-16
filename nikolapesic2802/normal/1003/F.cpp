#include <bits/stdc++.h>

using namespace std;
const int mod=341606371735362037;
int main()
{
    int n;
    scanf("%i",&n);
    char s[100001];
    string reci[n];
    int velicina=-1;
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        velicina++;
        reci[i]=s;
        velicina+=reci[i].size();
    }
    /*for(int i=0;i<n;i++)
    {
        cout << reci[i] << endl;
    }*/
    vector<pair<long long,pair<pair<int,int>,int> > > hashevi;
    for(int i=0;i<n;i++)
    {
        int sss=-1;
        long long h=0;
        for(int j=i;j<n;j++)
        {
            sss++;
            h=(h*(long long)28)%mod;
            h+=27;
            h=(h*(long long)28)%mod;
            for(unsigned int k=0;k<reci[j].size();k++)
            {
                h+=reci[j][k]-'a'+1;
                h=(h*(long long)28)%mod;
            }
            sss+=reci[j].size();
            hashevi.push_back(make_pair(h,make_pair(make_pair(i,j),sss)));
        }
    }
    int save=-1;
    sort(hashevi.begin(),hashevi.end());
    int vel=1;
    long long pred=hashevi[0].first;
    int siz=hashevi[0].second.second;
    int granica=hashevi[0].second.first.second;
    //printf("%i\n",siz);
    for(unsigned int i=1;i<hashevi.size();i++)
    {
        //printf("%lld, od: %i, do: %i   %i\n",hashevi[i].first,hashevi[i].second.first.first,hashevi[i].second.first.second,save);
        if(hashevi[i].first==pred)
        {
            if(hashevi[i].second.first.first>granica&&hashevi[i].second.second==siz)
            {
                vel++;
                granica=hashevi[i].second.first.second;
            }
        }
        else
        {
            if(vel>1)
            {
                int ssssave=siz*vel-(hashevi[i-1].second.first.second-hashevi[i-1].second.first.first+1)*vel;
                if(save==-1||save<ssssave)
                {
                    save=ssssave;
                }
            }
            vel=1;
            pred=hashevi[i].first;
            siz=hashevi[i].second.second;
            granica=hashevi[i].second.first.second;
        }
    }
    //printf("%i %i\n",velicina,save);
    if(save==-1)
    {
        save=0;
    }
    printf("%i\n",velicina-save);
    return 0;
}