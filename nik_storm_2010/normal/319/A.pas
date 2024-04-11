const module=1000000007;
var
  s2,s4:array[0..1000] of int64; ans:int64; d,i:longint; s:string; x:char;


begin

  s2[0]:=1; for i:=1 to 1000 do s2[i]:=(s2[i-1]*2) mod module;
  s4[0]:=1; for i:=1 to 1000 do s4[i]:=(s4[i-1]*4) mod module;
  ans:=0;
  readln(s); d:=length(s);
  for i:=1 to d do
  begin
    if s[i]='1' then ans:=(ans+((s2[i-1]*s4[d-i]) mod module)) mod module;
  end;
  writeln(ans);

end.