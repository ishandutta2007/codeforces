#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ll a,b;
	cin>>a>>b;
	vector<int> l(a);
	vector<int> l1(a);
	vector<int> l2(a);
	vector<int> l3;
	int cntb=0;
	for (int i=0;i<a;i++){
        cin>>l[i];
	}
	for (int j=1;j<=b;j++){
        int cnt=0;
        l3.clear();
        for (int i=0;i<a;i++){
            if (l1[i]==0){
                if (cntb==a-b+j){
                    break;
                }
                if(find(l3.begin(),l3.end(),l[i])==l3.end()){
                    l1[i]=1;
                    l2[i]=j;
                    l3.push_back(l[i]);
                    cnt++;
                    cntb++;
                }
            }
        }
	}
	for (int i=0;i<a;i++){
        if (l2[i]==0){
            cout<<"NO";
            return 0;
        }
	}
	cout<<"YES"<<endl;
	for (int i=0;i<a;i++){
        cout<<l2[i]<<" ";
	}
}