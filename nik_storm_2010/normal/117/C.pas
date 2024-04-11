type ee=record nx,tt:longint; end;
var
  e:array[1..15000000] of ee; start,prev,used,cyc:array[1..5000] of longint;
  g:array[1..5000,1..5000] of byte; n,i,j,k:longint; c:char;


procedure dfs(nom,p:longint);
var i,j,k:longint;
begin
  used[nom]:=1; prev[nom]:=p; i:=start[nom];
  while i<>0 do
  begin
    if used[e[i].tt]=0 then dfs(e[i].tt,nom) else
    if used[e[i].tt]=1 then
    begin
      j:=nom; k:=n; cyc[k]:=j;
      while j<>e[i].tt do
      begin
        j:=prev[j]; dec(k);
        cyc[k]:=j;
      end;
      for i:=n downto 1 do
        if g[cyc[i],cyc[i-2]]=1 then
        begin
          writeln(cyc[i-2],' ',cyc[i-1],' ',cyc[i]);
          halt;
        end
          else
        begin
          cyc[i-1]:=cyc[i];
        end;
    end;
    i:=e[i].nx;
  end;
  used[nom]:=2;
end;


procedure addedge(a,b:longint);
begin
  inc(k); e[k].tt:=b; e[k].nx:=start[a];
  start[a]:=k;
end;


begin

  readln(n);
  for i:=1 to n do
  begin
    for j:=1 to n do
    begin
      read(c);
      if c='1' then begin addedge(i,j); g[i,j]:=1; end;
    end;
    readln;
  end;
  for i:=1 to n do if used[i]=0 then dfs(i,0);
  writeln(-1);

end.