Var
   leng,i,left,right,error,pred: longint;
    answer,number: int64;
     s: string;



function prov(s:string):int64;
var error:longint;
     c:int64;
 begin
  val(s,c,error);
   exit(c);
 end;


Begin

  answer:=0;
   readln(left,right);
    s:=''; pred:=left;
     while prov(s)<=right do
      begin
       leng:=length(s);
        i:=leng;
         while i<>0 do
          if s[i] = '4'
           then
            begin
             s[i]:='7';
              break;
            end
           else
            begin
             s[i]:='4';
              dec(i);
            end;
       if i=0 then s:='4'+s;

       val(s,number,error);
        if number <= right
         then
          begin
           if number >= pred
            then
             begin
              answer:=answer + ((number-pred+1) * number);
               pred:=number+1;
             end;
          end
         else
          begin
           answer:=answer + ((right-pred+1) * number);
          end;
      end;
  writeln(answer);

End.