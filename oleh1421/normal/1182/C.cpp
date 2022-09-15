#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
bool ok(char c){
    return (c=='a' || c=='e' || c=='o' || c=='i' || c=='u');
}
string s[100001];
vector<int> mp[100001][51];
vector<int>mp1[100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    vector<pair<pair<int,int>,int> >v;
    for (int i=1;i<=n;i++){
        string t;cin>>t;
        int cnt=0;
        int last=0;
        for (auto j:t){
            if (ok(j)){
                cnt++;
                last=(j-'a'+1);
            }
        }
        s[i]=t;
        v.push_back({{cnt,last},i});
    }
    vector<pair<pair<int,int>,pair<int,int> > >ans;
    sort(v.begin(),v.end());
    set<pair<int,int> >st;
    for (int i=0;i<n;i++){
        mp[v[i].first.first][v[i].first.second].push_back(v[i].second);
        st.insert(v[i].first);
    }
    vector<pair<int,int> >good;
    vector<pair<int,int> >left;
    set<int>st1;
    for (auto p:st){
        for (int i=1;i<(int)mp[p.first][p.second].size();i+=2){
             good.push_back({mp[p.first][p.second][i-1],mp[p.first][p.second][i]});
        }
        if ((int)mp[p.first][p.second].size()%2){
            left.push_back({p.first,mp[p.first][p.second].back()});
            mp1[p.first].push_back(mp[p.first][p.second].back());
            st1.insert(p.first);
        }
    }
    vector<pair<int,int> >bad;
    for (auto p:st1){
        for (int i=1;i<(int)mp1[p].size();i+=2){
             bad.push_back({mp1[p][i-1],mp1[p][i]});
        }
    }
    while (bad.size()<good.size()){
        bad.push_back(good.back());
        good.pop_back();
    }
    int m=min((int)bad.size(),(int)good.size());
    cout<<m<<endl;
    for (int i=0;i<m;i++){
        cout<<s[bad[i].first]<<" "<<s[good[i].first]<<endl;
        cout<<s[bad[i].second]<<" "<<s[good[i].second]<<endl;
    }


    return 0;
}
//1-0
//3-1
//5-2
//7 3
//9 4