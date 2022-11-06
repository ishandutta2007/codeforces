#include<bits/stdc++.h>
#define ll long long int
#define ul unsigned long long int 
#define pb push_back

using namespace std;

std::string trim(const std::string& str,
                 const std::string& whitespace = " \t")
{
    const auto strBegin = str.find_first_not_of(whitespace);
    if (strBegin == std::string::npos)
        return ""; // no content

    const auto strEnd = str.find_last_not_of(whitespace);
    const auto strRange = strEnd - strBegin + 1;

    return str.substr(strBegin, strRange);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	int i=0;
	string name,ip,ip1;
	map<string,string> s;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>name;
		cin>>ip;
		s.insert(pair<string,string>(ip,name));
	}
	for(int i=0;i<m;i++)
	{
		cin>>name;
		cin>>ip;
		ip1=trim(ip);
		ip1.pop_back();
		cout<<name<<" "<<ip<<" #"<<s.lower_bound(ip1)->second<<"\n";
	}
}