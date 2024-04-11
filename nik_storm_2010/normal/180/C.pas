var
    st:ansistring; d,i,ans,b,s,tekb,teks:longint;


begin

  readln(st);
   d:=length(st);
  ans:=maxlongint;

  for i:=1 to d do
   if ord(st[i]) < 96
   then inc(b)
  else inc(s);

  for i:=0 to d+1 do
   begin
    if (i<>0) and (i<>d+1)
     then if ord(st[i])<96 then inc(tekb) else inc(teks);

    if (teks+(b-tekb))<ans
     then
      begin
       ans:=teks+(b-tekb);
      end;
   end;
  if (b=0) or (s=0)
   then writeln(0)
  else writeln(ans);

end.