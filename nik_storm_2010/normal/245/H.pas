const max=5010;
var
  f:array[0..max,0..max] of longint; pal:array[0..max,0..max] of boolean;
  n,d,i,l,r:longint; s:ansistring;


begin
  readln(s); d:=length(s);
  for i:=1 to d do for l:=1 to d do
  begin
    r:=l+i-1; if (r>d) then break;
    if (i<=2) then
    begin
      if (i=1) or (s[l]=s[r]) then pal[l,r]:=true else pal[l,r]:=false
    end
      else
    begin
      if (pal[l+1,r-1]) and (s[l]=s[r]) then pal[l,r]:=true else pal[l,r]:=false;
    end;
    f[l,r]:=f[l,r-1]+f[l+1,r]-f[l+1,r-1];
    if (pal[l,r]) then inc(f[l,r]);
  end;
  readln(n);
  for i:=1 to n do
  begin
    readln(l,r);
    writeln(f[l,r]);
  end;

end.