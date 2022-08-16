    #include <bits/stdc++.h>
    using namespace std;
     
    #define pb push_back
    #define f(i,n) for(int i=0;i<n;i++)
    #define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
    #define vi vector<int>
     
    const int N = 1e5,NN=1e6;
     
    string ans;
    string data[N];
    vi KMP(2*NN+10,0);
    int p;
     
    char get(int i,int id)
    {
        if(i<p) return data[id][i];
        if(i==p) return '#';
        
        return ans[(int)ans.length()-2*p+i-1];
    }
     
    void process(int id)
    {
      p = min(data[id].length(),ans.length());
      
      for(int i=1;i<=2*p;i++)
      {  
        int h = KMP[i-1];
          
        while(get(i,id) != get(h,id) && h) h = KMP[h-1];
          
        if(get(h,id) == get(i,id)) h++;   
          
        KMP[i] = h;  
      }
        
      for(int j=KMP[2*p];j<data[id].length();j++) ans.pb(data[id][j]);  
    }
     
    void solve()
    {
      int n;
      cin>> n;
        
      f(i,n) cin >> data[i];
        
      ans = data[0];
        
      f(i,n-1) process(i+1);
        
      cout << ans;
    }
     
    int main()
    {
        fast;
       
        solve();
    }