// test, Luogu NOIP project 2021

#include<bits/stdc++.h>
using namespace std;

int main()
{
    /*q=int(input())
    for i in range(q):
    	s=input()
    	t=input()
    	n=len(s)
    	m=len(t)
    	ans=False
    	for i in range(n):
    		for j in range(0,n-i):
    			k=m-1-j
    			if i+j<k:
    				continue
    			l1=i
    			r=i+j
    			l2=r-k
    			if s[l1:r+1]+s[l2:r][::-1]==t:
    				ans=True
    print('YES' if ans else 'NO')
    return 0;*/
    int q;
    cin >> q;
    for(int i = 1;i <= q;i++)
    {
    	string s,t;
    	cin >> s >> t;
    	int n = s.length(),m = t.length();
    	bool flag = 1,ans = 0;
    	for(int i = 0;i <= n - 1;i++)//
		{
			for(int j = 0;j <= n - i - 1 && j <= m - 1;j++)//in-i-1m-1 
			{
				//cout << i <<" i "<<j<<" j "<<endl;
				int k = m - 1 - j;// 
				if(i + j < k) continue;// 
				int l1 = i;// 
				int r = i + j;// 
				int l2 = r - k;// 
				//cout << l1 <<" l1 "<<r<<" r "<<l2 << " l2 "<<endl;
				flag = 1;
				//string answ = "";
				int top = 0;
				for(int w = l1;w <= r;w++) 
				{
					//cout << w << " w "<<s[w]<<" "<<top <<" top "<<t[top]<<" ";
					if(s[w] != t[top++]){
						flag = 0;
						//cout << "false";
					}
					//cout<<endl;
				}
				for(int y = r - 1;y >= l2;y--)
				{
					//cout << y << " y "<<s[y]<<" "<<top <<" top "<<t[top]<<" ";
					if(s[y] != t[top++]){
						flag = 0;
						//cout << "false";
					}
					//cout<<endl;
				}
				//cout << answ <<endl << t <<endl;
				//if(answ == t)
				//{
				if(flag == 1){
					//cout << l1 <<" "<<r <<" "<<l2 <<" true"<<endl;
					ans = true;
					break;
				}
				//}
			} 
		}
		if(ans == true) cout << "YES";
		else cout << "NO";
		cout << endl; 
	}
}