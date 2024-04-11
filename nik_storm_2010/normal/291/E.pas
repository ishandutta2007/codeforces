var
    edge:array[1..2,1..100000] of longint; l:array[1..1000000] of longint; st:array[1..100000] of string; sim:char;
      t:array[1..1000000] of char; f,start:array[0..1000000] of longint; ans,a,d,n,i:longint; need:string;


procedure kmp(nom:longint);
var k,i:longint;
begin
  k:=f[nom-1];
  while (k>0) and (t[k+1]<>t[nom]) do k:=f[k];
  if t[k+1]=t[nom] then inc(k);
  f[nom]:=k;
  if f[nom]=d then inc(ans);
end;


procedure dfs(nom,free:longint);
var i,e:longint;
begin
  e:=start[nom];
  while e<>0 do
    begin
      for i:=1 to l[e] do begin t[free+i-1]:=st[e][i]; kmp(free+i-1); end;
      dfs(edge[1,e],free+l[e]);
      e:=edge[2,e];
    end;
end;


begin

  readln(n);
  for i:=1 to n-1 do
    begin
      readln(a,sim,st[i]);
      edge[1,i]:=i+1; edge[2,i]:=start[a]; l[i]:=length(st[i]);
      start[a]:=i;
    end;
  readln(need); d:=length(need);
  for i:=1 to d do
    begin
      t[i]:=need[i];
      if i<>1 then kmp(i);
    end;
  t[d+1]:='$';
  ans:=0;
  dfs(1,d+2);
  writeln(ans);

end.