uses math;
var
  k1,k2,kk:array['A'..'Z'] of longint; s1,s2:ansistring;
  kol,d,x,i:longint; c:char;


procedure inputdata;
begin
  assign(input,'input.txt'); reset(input);
  readln(s1); readln(s2);
  close(input);
end;


procedure outputdata;
begin
  assign(output,'output.txt'); rewrite(output);
  writeln(kol); writeln(s1);
  close(output);
end;


function next(sim:char):char;
var c:char;
begin
  for c:=sim to 'Z' do if k2[c]<>0 then exit(c);
end;


begin

  inputdata; d:=length(s1);
  for i:=1 to d do
  begin
    inc(kk[s1[i]]); inc(k1[s1[i]]); inc(k2[s2[i]]);
  end;
  for c:='A' to 'Z' do
  begin
    x:=min(k1[c],k2[c]); k1[c]:=k1[c]-x; k2[c]:=k2[c]-x;
    kol:=kol+k2[c];
  end;
  c:=next('A');
  for i:=1 to d do
  begin
    if k1[s1[i]]=0 then continue;
    if (k1[s1[i]]=kk[s1[i]]) or (c<s1[i]) then
    begin
      dec(k1[s1[i]]); dec(kk[s1[i]]); s1[i]:=c;
      dec(k2[c]); c:=next(c);
    end
      else
    begin
      dec(kk[s1[i]]);
    end;
  end;
  outputdata;

end.