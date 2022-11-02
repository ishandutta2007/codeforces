var
  a:array[0..200,0..200] of char; ans,n,m,i,j,x,y,w:longint;


function check(x,y:longint):boolean;
var i:longint;
begin
  check:=false;
  if odd(x)
  then begin for i:=y+1 to m do if (a[x,i]='W') or (a[x+1,i]='W') then check:=true; end
  else begin for i:=y-1 downto 1 do if (a[x,i]='W') or (a[x+1,i]='W') then check:=true; end;
end;


begin
  readln(n,m);
  for i:=1 to n do
  begin
    for j:=1 to m do
    begin
      read(a[i,j]);
      if a[i,j]='W' then inc(w);
    end;
    readln;
  end;
  ans:=0; x:=1; y:=1;
  while (w>0) do
  begin
    if not check(x,y) then inc(x) else
    begin
      if odd(x) then inc(y) else dec(y);
    end;
    if a[x,y]='W' then dec(w); inc(ans);
  end;
  writeln(ans);

end.