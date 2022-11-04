#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        int tot=0;
        vector<int> cnt(n+1);
        vector<pair<int,int>> event;
        for(int i=1;i<=n;i++)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            event.push_back({l,-i});
            event.push_back({r,i});
        }
        sort(event.begin(),event.end());
        set<int> scanline;
        for(auto &e:event)
        {
            int sid=abs(e.second);
            if(e.second<0)
            {
                if(scanline.empty())cnt[sid]--;
                scanline.insert(sid);
            }
            else
            {
                scanline.erase(sid);
                if(scanline.empty())cnt[sid]--;
            }
            if(scanline.empty())tot++;
            if(scanline.size()==1)cnt[*scanline.begin()]++;
        }
        int ext=-1;
        for(int i=1;i<=n;i++)
            ext=max(ext,cnt[i]);
        printf("%d\n",tot+ext);
    }
    return 0;
}