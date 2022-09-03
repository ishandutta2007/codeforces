#include <iostream>
#include <vector>
using namespace std;
int main(){
	vector<int> ans;
	int n,v;
	cin>>n>>v;
	for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			int minn=1000000;
			for(int j=1;j<=k;j++){
					int y;
					cin>>y;
					if(minn>y)minn=y;
			}
			if(minn<v)ans.push_back(i);
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)cout<<ans[i]<<' ';
	return 0;
}