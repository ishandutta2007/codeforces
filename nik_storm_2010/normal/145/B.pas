var
 a1,a2,a3,a4,i,j:longint;
  s,s1,s2:ansistring;



begin

  readln(a1,a2,a3,a4);
   s:='';
    for i:=1 to a3 do s:=s+'47';
     a1:=a1-a3;
    a2:=a2-a3;
   a4:=a4-a3+1;
  if (a1<0) or (a2<0) or (a4<0) or (a4>2) then begin writeln('-1'); halt; end;
   if a4=1
    then
     begin
      if a1=0
       then
        begin
         s:='7'+s;
          dec(a2);
         if a2<0 then begin writeln('-1'); halt; end;
        end
       else
        begin
         s:=s+'4';
          dec(a1);
         if a1<0 then begin writeln('-1'); halt; end;
        end;
     end;
   if a4=2
    then
     begin
      s:='7'+s+'4';
       dec(a1);
       dec(a2);
      if (a1<0) or (a2<0) then begin writeln('-1'); halt; end;
     end;
   for i:=length(s) downto 1 do
    if s[i]='7'
     then
      begin
       s1:=copy(s,1,i);
        s2:=copy(s,i+1,length(s)-i);
         for j:=1 to a2 do s1:=s1+'7';
        s:=s1+s2; a2:=0;
       break;
      end;
   for i:=1 to length(s) do
    if s[i]='4'
     then
      begin
       s1:=copy(s,1,i);
        s2:=copy(s,i+1,length(s)-i);
         for j:=1 to a1 do s1:=s1+'4';
        s:=s1+s2; a1:=0;
       break;
      end;
  if (a1=0) and (a2=0) then writeln(s) else writeln('-1');

end.