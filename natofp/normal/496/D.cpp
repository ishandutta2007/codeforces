#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=2e5+5;
int n;
int pos1[nax];
int pos2[nax];
int ile1=1;
int ile2=1;
int a[nax];
int ile[nax];


int main()
{
    cin>>n;
    for(int i=0;i<nax;i++)
    {
        pos1[i]=pos2[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        if(x==1)
        {
            pos1[ile1++]=i;
            ile[i]=ile2-1;
        }
        else
        {
            pos2[ile2++]=i;
            ile[i]=ile1-1;
        }
        a[i]=x;
    }
    //for(int i=1;i<=n;i++) cout<<i<<" "<<ile[i]<<endl;
    ile1--;
    ile2--;
    vector<pair<int,int> > ans;
    for(int t=1;t<=n;t++)
    {
        int sety1=0;
        int sety2=0;
        int pkt1=0;
        int pkt2=0;
        while(true)
        {
            int pot1=pkt1+t;
            int pot2=pkt2+t;
            if(pos1[pot1]==0 && pos2[pot2]==0) break;
            else if(pos1[pot1]==0)
            {
                sety2++;
                pkt2=pot2;
            }
            else if(pos2[pot2]==0)
            {
                sety1++;
                pkt1=pot1;
            }
            else
            {
                if(pos1[pot1]<pos2[pot2])
                {
                    sety1++;
                    pkt1=pot1;
                    pkt2=ile[pos1[pkt1]];
                }
                else
                {
                    sety2++;
                    pkt2=pot2;
                    pkt1=ile[pos2[pkt2]];
                }
            }
        }
        if(sety1==sety2) continue;
        else if(sety1>sety2)
        {
            int k=ile[pos1[pkt1]];
            if(pos2[k+1]!=0) continue;
            if(pos1[pkt1+1]==0) ans.push_back({sety1,t});
        }
        else
        {
            int k=ile[pos2[pkt2]];
            if(pos1[k+1]!=0) continue;
            if(pos2[pkt2+1]==0) ans.push_back({sety2,t});
        }
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++) cout<<ans[i].first<<" "<<ans[i].second<<endl;
    return 0;
}