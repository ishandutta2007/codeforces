    #include <bits/stdc++.h>
    typedef unsigned long long ll;
    using namespace std;
    vector<int> f(int x,string s){
         int n=(int)s.size();
         vector<int>v;
         for (int i=0;i<x;i++) {
                v.push_back(s[i]-'0');
         }
         vector<int>u;
         for (int i=x;i<n;i++) u.push_back(s[i]-'0');
         reverse(v.begin(),v.end());
         reverse(u.begin(),u.end());
         while (v.size()<u.size()) v.push_back(0);
         while (u.size()<v.size()) u.push_back(0);
         int k=(int)u.size();
         vector<int>res(k,0);
         for (int i=0;i<k;i++) res[i]=v[i]+u[i];
         for (int i=0;i<k-1;i++){
            res[i+1]+=res[i]/10;
            res[i]%=10;
         }
         if (res[k-1]>9){
            res[k-1]%=10;
            res.push_back(1);
         }
         while (res.size()<100000) res.push_back(0);
         reverse(res.begin(),res.end());
         return res;
    }
    int main()
    {
       ll n;cin>>n;
       string s;cin>>s;
       int l=-1;
       for (int i=0;i<=n/2;i++){
           if (s[i]-'0') l=i;
       }
       int r=-1;
       for (int i=n-1;i>n/2;i--){
           if (s[i]-'0') r=i;
       }
      // cout<<l<<" "<<r<<endl;
       vector<int>v;
       if (l!=-1) v=f(l,s);
       vector<int>u;
       if (r!=-1) u=f(r,s);
       vector<int>res=v;
	   if (v.empty() || (!u.empty() && u<v)) res=u;
       reverse(res.begin(),res.end());
       while (res.back()==0) res.pop_back();
       reverse(res.begin(),res.end());
       for (auto i:res) cout<<i;
       return 0;
    }