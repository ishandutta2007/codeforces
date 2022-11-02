var
  s:ansistring;
  ans,h:array [1..1000000] of longint;
procedure init;
var
  ch:char;
  i,l,o,tot:longint;
begin
  tot:=0; o:=0;
  readln(s);
  for i:=1 to length(s) do
  begin
    if s[i]='(' then inc(o)
    else if s[i]=')' then dec(o)
    else
    begin
      inc(tot);
      ans[tot]:=1;
      dec(o);
      h[tot]:=o;
    end;
    if o<0 then
    begin
      writeln('-1');
      halt;
      close(output);
    end;
  end;
  ans[tot]:=ans[tot]+o;
  o:=0; tot:=0;
  for i:=1 to length(s) do
  begin
    if s[i]='(' then inc(o)
    else if s[i]=')' then dec(o)
    else
    begin
      inc(tot);
      o:=o-ans[tot];
    end;
    if o<0 then
    begin
      writeln('-1');
      halt;
    end;
  end;
  for i:=1 to tot do writeln(ans[i]);
end;
begin
  init;
end.