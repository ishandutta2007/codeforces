    #include <bits/stdc++.h>
    using namespace std;
     
    string itos(int i)
    {
        std::stringstream ss;
        std::string str;
        ss << i;
        ss >> str;
        return str;
    }
     
    //  127 131 
    long long pot1[33];
    long long pot2[33];
     
    int main() {
    	ios_base::sync_with_stdio(0);
    	cin.tie(0);
    	cout.tie(0);
    	map <pair<long long,long long>,int> mapa;
    	int n;
    	cin>>n;
    	string str;
    	pot1[0]=1;
    	pot2[0]=1;
    	for(int i=1;i<33;i++)
    	{
    		pot1[i]=pot1[i-1]*127;
    		pot1[i]%=1000000007;
    		pot2[i]=pot2[i-1]*131;
    		pot2[i]%=1000000009;
    	}
    	long long h1,h2;
    	for(int i=0;i<n;i++)
    	{
    		cin>>str;
    		h1=0;
    		h2=0;
    		for(int j=0;j<str.size();j++)
    		{
    			h1+=pot1[j]*str[j];
    			h1%=1000000007;
    			h2+=pot2[j]*str[j];
    			h2%=1000000009;
    		}
    		if(mapa[make_pair(h1,h2)]==0) cout<<"OK"<<endl;
    		else cout<<str<<itos(mapa[make_pair(h1,h2)])<<endl;
    		mapa[make_pair(h1,h2)]++;
    	}
    	return 0;
    }