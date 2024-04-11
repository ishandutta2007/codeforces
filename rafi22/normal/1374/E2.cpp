#include <bits/stdc++.h>

using namespace std;

vector <pair<long long,long long> > alice;
vector <pair<long long,long long> > bob;
vector <pair<long long,long long> > together;
vector <pair<long long,long long> > none;
vector <long long> setAns;
long long n,m,k,a,ans=0;
long long inf=1000000000000000007;

pair<long long,vector <long long> > licz(int sr)
{
    long long res1=0;
    vector <long long> v;
    for(int i=0; i<sr; i++)
    {
        res1+=together[i].first;
        v.push_back(together[i].second);
    }
    long long ile=max((long long)0,min((long long)min(alice.size(),bob.size()),k-sr));
   // cout<<sr<<" "<<ile<<endl;
    if(2*ile+sr>m) return {inf,v};
    for(int i=0; i<ile; i++)
    {
        res1+=alice[i].first+bob[i].first;
        v.push_back(alice[i].second);
        v.push_back(bob[i].second);
    }

    int i1=sr,i2=ile,i3=ile,i4=0;

    for(int i=sr+2*ile;i<m; i++)
    {
        long long mini=inf;
        if(i1<together.size()) mini=min(mini,together[i1].first);
        if(i2<alice.size()) mini=min(mini,alice[i2].first);
        if(i3<bob.size()) mini=min(mini,bob[i3].first);
        if(i4<none.size()) mini=min(mini,none[i4].first);
        if(i1<together.size()&&together[i1].first==mini)
        {
            res1+=together[i1].first;
            v.push_back(together[i1].second);
            i1++;
        }
        else if(i2<alice.size()&&alice[i2].first==mini)
        {
            res1+=alice[i2].first;
            v.push_back(alice[i2].second);
            i2++;
        }
        else if(i3<bob.size()&&bob[i3].first==mini)
        {
            res1+=bob[i3].first;
            v.push_back(bob[i3].second);
            i3++;
        }
        else if(i4<none.size()&&none[i4].first==mini)
        {
            res1+=none[i4].first;
            v.push_back(none[i4].second);
            i4++;
        }
    }
    return {res1,v};
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    char ch1,ch2;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>ch1>>ch2;
        if(ch1=='1'&&ch2=='1') together.push_back({a,i});
        else if(ch1=='1') alice.push_back({a,i});
        else if(ch2=='1') bob.push_back({a,i});
        else none.push_back({a,i});
    }
    sort(alice.begin(),alice.end());
    sort(bob.begin(),bob.end());
    sort(together.begin(),together.end());
    sort(none.begin(),none.end());
    if(together.size()+min(alice.size(),bob.size())<k)
    {
        cout<<-1;
        return 0;
    }
    if((k-together.size())*2>m-together.size())
    {
        cout<<-1;
        return 0;
    }
    long long l=max((long long)0,max(k-(m-k),(k-(long long)min(alice.size(),bob.size())))),p=min(k,(long long)together.size()),sr,ans=inf,res1,res2;
    while(l<=p)
    {
        res1=inf;
        res2=inf;
        sr=(l+p)/2;
        pair<long long,vector<long long>> p1,p2;

        p1=licz(sr);
        res1=p1.first;
        if(sr+1<=together.size())
        {
            p2=licz(sr+1);
            res2=p2.first;
        }
        if(res1<res2)
        {
            ans=min(res1,ans);
            p=sr-1;
            setAns=p1.second;
        }
        else
        {
            ans=min(res2,ans);
            l=sr+1;
            setAns=p2.second;
        }


    }
    cout<<ans<<endl;
    for(int i=0;i<setAns.size();i++) cout<<setAns[i]<<" ";

    return 0;
}