uses math;
var
  a,b,c:array[1..10,1..100] of longint; sum:array[0..1000] of longint;
  ans,i,j,x,n,m,k:longint; s:string;


function solution:longint;
var res,i,j,z:longint;
begin
  z:=k; res:=0;
  for i:=1000 downto 1 do for j:=1 to sum[i] do
  begin
    res:=res+i; dec(z);
    if z=0 then exit(res);
  end;
  solution:=res;
end;


begin

  readln(n,m,k);
  for i:=1 to n do
  begin
    readln(s);
    for j:=1 to m do readln(a[i,j],b[i,j],c[i,j]);
  end;
  ans:=0;
  for i:=1 to n do for j:=1 to n do
  begin
    fillchar(sum,sizeof(sum),0);
    for x:=1 to m do if a[i,x]<=b[j,x] then inc(sum[b[j,x]-a[i,x]],c[i,x]);
    ans:=max(ans,solution);
  end;
  writeln(ans);

end.