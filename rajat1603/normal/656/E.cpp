#include "bits/stdc++.h"
using namespace std;
const int N = 11;
int n;
int arr[N][N];
int ans = 0;
int readcol(int row , int col){
	scanf("%d" , &arr[row][col]);
	return (col < n) ? readcol(row , col + 1) : 0;
}
int read(int row){
	readcol(row , 1);
	return (row < n) ? read(row + 1) : 0;
}
int fuckj(int k , int i , int j){
	arr[i][j] = min(arr[i][j] , arr[i][k] + arr[k][j]);
	return (j < n) ? fuckj(k , i , j + 1) : 0;
}
int fucki(int k , int i){
	fuckj(k , i , 1);
	return (i < n) ? fucki(k , i + 1) : 0;
}
int fuckk(int k){
	fucki(k , 1);
	return (k < n) ? fuckk(k + 1) : 0;
}
int main(){
	memset(arr , 0 , sizeof(arr));
	scanf("%d" , &n);
	read(1);
	fuckk(1);
	printf("%d\n" , *max_element(&arr[1][1] , &arr[n][n]));
}