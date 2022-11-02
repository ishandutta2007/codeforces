const lim=100000;
var
  v:array[0..lim] of longint; was:array[0..lim] of boolean; n,i:longint;


procedure dfs(i:longint);
begin
  if was[i] then exit; was[i]:=true;
  if was[(i+n div 2) mod n] then
  begin
    if v[(i+n div 2) mod n]=(i*2) mod n
      then begin v[i]:=(i*2+1) mod n; dfs((i*2+1) mod n); end
      else begin v[i]:=(i*2) mod n; dfs((i*2) mod n); end;
  end
    else
  begin
    v[i]:=(i*2) mod n; dfs((2*i) mod n);
    if was[(i+n div 2) mod n]=false then
    begin
      v[i]:=(i*2+1) mod n; v[(i+n div 2) mod n]:=(i*2) mod n;
      dfs((i*2+1) mod n);
    end;
  end;
end;


begin

  readln(n);
  if n mod 2=1 then writeln(-1) else
  begin
    dfs(0); i:=0;
    while n<>0 do
    begin
      write(i,' '); dec(n);
      i:=v[i];
    end;
    write(0);
  end;

end.