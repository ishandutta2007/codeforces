#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

//ifstream cin ("input.txt" );
//ofstream cout("output.txt");

int main() {

   int n,m;
   cin>>n>>m;
   char g[n+1][m+1];
   int k[n+1][m+1];
   bool used[n+1][m+1];
   for (int i=1;i<=n;i++)
	   for (int j=1;j<=m;j++) 
	    cin>>g[i][j];
	   
   for (int i=1;i<=n;i++)
	   for (int j=1;j<=m;j++)    
        { k[i][j]=0;
			if (g[i][j]=='P') 
		 {
			 if (i-1>=1) 
				 if (g[i-1][j]=='W') k[i][j]++;
			 if (i+1<=n) 
				 if (g[i+1][j]=='W') k[i][j]++;
			 if (j+1<=m)
				 if (g[i][j+1]=='W') k[i][j]++;
			 if (j-1>=1)
				 if (g[i][j-1]=='W') k[i][j]++;
		 } else k[i][j]=5;used[i][j]=false;}
	int e=0;

	for (int i=1;i<=n;i++)
	   for (int j=1;j<=m;j++)
	   {
         if (g[i][j]!='W') continue;
         int min=5;
	         if (i-1>=1) 
				 if (k[i-1][j]<min&!used[i-1][j]) min=k[i-1][j];
             if (i+1<=n) 
				 if (k[i+1][j]<min&!used[i+1][j]) min=k[i+1][j];
	         if (j-1>=1) 
				 if (k[i][j-1]<min&!used[i][j-1]) min=k[i][j-1];
	         if (j+1<=m) 
				 if (k[i][j+1]<min&!used[i][j+1]) min=k[i][j+1];
			 if (min==5) continue;
		     if (i-1>=1) 
				 if (k[i-1][j]==min) {used[i-1][j]=true; e++;continue;}
             if (i+1<=n) 
				 if (k[i+1][j]==min) {used[i+1][j]=true; e++;continue;}
	         if (j-1>=1) 
				 if (k[i][j-1]==min) {used[i][j-1]=true; e++;continue;}
	         if (j+1<=m) 
				 if (k[i][j+1]==min) {used[i][j+1]=true; e++;continue;}
             			 
	   }		   
	   cout<<e;
    return 0;
}