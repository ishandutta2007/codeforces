uses math;
var
 s,q1,q2,q3,q4,pred,tek : ansistring;
  p1,p2,p3,p4,a1,a2,a3,a4 : longint;
   n,k,i,nom : longint;



procedure outputdata(answer:string);
 begin

   writeln(answer);
    halt;

 end;



procedure razbor(s:ansistring; var ss:ansistring);
var i,leng,tek : longint;
 begin

  ss:='';
   leng:=length(s); tek:=0;
    for i:=leng downto 1 do
     begin

      if (s[i]='a') or (s[i]='e') or (s[i]='i') or (s[i]='o') or (s[i]='u')
       then
        begin
         inc(tek);
        end;
        ss:=s[i]+ss;
       if tek=k then exit;

      end;
   str(nom,ss);
    inc(nom);

 end;



procedure srav(s1,s2:ansistring; var p:boolean);
var leng1,leng2,i : longint;
 begin

  p:=false;
   leng1:=length(s1); leng2:=length(s2);
   if leng1<>leng2 then exit;

   for i:=1 to leng1 do
    if s1[i]<>s2[i] then exit;
  p:=true;

 end;



begin

  readln(n,k); a1:=1; a2:=1; a3:=1; a4:=1; nom:=1;
   for i:=1 to n do
    begin

      readln(s);
       razbor(s,q1);

      readln(s);
       razbor(s,q2);

      readln(s);
       razbor(s,q3);

      readln(s);
       razbor(s,q4);

      p1:=0; p2:=0; p3:=0; p4:=0;
      if (q1=q2) and (q2=q3) and (q3=q4) then p1:=1;
       if (q1=q2) and (q3=q4) then p2:=1;
        if (q1=q3) and (q2=q4) then p3:=1;
         if (q1=q4) and (q2=q3) then p4:=1;

     a1:=min(p1,a1); a2:=min(p2,a2);
     a3:=min(p3,a3); a4:=min(p4,a4);

    end;
  if a1=1 then outputdata('aaaa');
  if a2=1 then outputdata('aabb');
  if a3=1 then outputdata('abab');
  if a4=1 then outputdata('abba');
  outputdata('NO');
end.